select p.code, p.name
from Districts d 
join VOTINGS v
join Parishes p 
join Municipalities m 
on d.region = 'M' 
and m.District = d.code 
and p.municipality = m.code 
and (v.parish = p.code and v.party = 'PSN')
where v.votes = 0

order by p.code