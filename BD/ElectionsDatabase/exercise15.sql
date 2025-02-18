select l.Party
from Lists l, Districts d
where l.District = d.code
and (d.name like '%o%' or d.name like '%O%')
and l.seats = 0
group by l.Party
having count(*) = 
    (select count(*)
    from Districts d1
    where d1.name like '%o%' or d1.name like '%O%')
order by l.party