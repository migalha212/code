select l.Party,l.seats
from Lists l join districts d join Parishes p join Municipalities m on
l.District = d.code and  m.District = d.code and p.municipality = m.code
where p.name = 'Mancelos' 
order by l.seats desc