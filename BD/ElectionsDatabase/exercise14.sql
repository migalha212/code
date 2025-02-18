select v.party, p.name, v.votes
from VOTINGS v 
join Parishes p 
on v.parish = p.code
where v.votes = (select max(v1.VOTES)
                from VOTINGS v1)