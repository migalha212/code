select code,name
from districts d
where code = (select District 
               from Municipalities m
                where code = (select municipality
                              from Parishes p
                              where p.name = 'Mancelos'))