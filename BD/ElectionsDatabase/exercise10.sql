select m.code,m.name,v.party, sum(votes) as VOTES
from Votings v
join Parishes p
join Municipalities m
on p.municipality = m.code
and v.parish = p.code
group by v.party
limit 40    
