select Party,Votes
from VOTINGS v 
where v.parish = (select code
                  from Parishes p
                  where p.name = 'Mancelos')
order by votes desc, party asc

