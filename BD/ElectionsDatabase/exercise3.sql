select code,name
from Parishes p
where p.municipality = (select code
                    from Municipalities m
                    where m.name = 'Espinho')
order by code  asc  