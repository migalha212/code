select m.name
from Municipalities m 
join Participations p
on m.District = p.District
where p.voters = (select max(p1.voters)
                    from Participations p1) 
order by m.name

