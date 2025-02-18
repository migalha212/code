DROP Trigger if EXISTS UpdatePartsTrigger;
DROP Trigger if EXISTS UnkownOwnerTrigger;
DROP Trigger if EXISTS PartLimitTrigger;
DROP Trigger if EXISTS UpdateViewsTrigger;
Drop View if EXISTS CarView;


Create Trigger UpdatePartsTrigger
after INSERT on RepairPart
For Each Row
Begin
    update Part
    set availableQuantity = availableQuantity - new.quantity
    where partId = new.partId;
END;


Create Trigger UnkownOwnerTrigger
after INSERT on Repair
for Each Row
when (new.clientId is NULL)
Begin
    update Repair
    set clientId = (select clientId from Car
                    where idCar = new.idCar)
    where repairId = new.repairId;
END;


Create Trigger PartLimitTrigger
Before INSERT on RepairPart
for Each Row
when (new.quantity > 
    (select availableQuantity from Part
    where partId = new.partId)) 
    and 
    not EXISTS (select * from PartModel
    where partId = new.partId 
    and modelId = (select modelId 
    from Repair join Car on Repair.idCar = Car.idCar
    where repairId = new.repairId)) 
Begin
    select raise(Abort,"Invalid Part/Insuficient Quantity");
End;

Create view CarView as
    select M.name as model,B.name as brand from Model M join Brand B
    on M.brandId = B.brandId;


Create Trigger UpdateViewsTrigger
instead of INSERT on CarView
Begin
    insert or ignore into Brand (name) values (new.brand);
    insert or ignore into Model (name,brandId) values (new.model,
        (select brandId from Brand where name = new.brand));
End;