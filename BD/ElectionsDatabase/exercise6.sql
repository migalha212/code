select d.name, p.voters, p.abstentions
from Districts d join Participations p on
d.code = p.District
where p.abstentions > 0.75 * p.voters
order by d.name