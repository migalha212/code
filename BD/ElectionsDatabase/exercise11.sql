select d.code, d.name, v.party, sum(votes) as VOTES
from Votings v 
join Districts d 
join Municipalities m 
join Parishes p 
on p.code = v.parish
and p.municipality = m.code
and m.District = d.code
group by v.party, d.code 
order by d.code asc, v.party asc