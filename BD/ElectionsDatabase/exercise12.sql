select v.Party, sum(votes) as VOTES
from Votings v 
join Parishes p
on p.code = v.parish
group by v.party