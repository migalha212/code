with per_district as (
    select d.code, d.name, v.party, Sum(v.votes) as votes
    from Districts d 
    join Municipalities m on m.District = d.code
    join Parishes p on p.municipality = m.code
    join Votings v on v.parish = p.code
    group by d.code, d.name, v.party
)

select v.name, p.designation, v.votes
from per_district v
join parties p on v.party = p.acronym
where (v.code, v.votes) in (
    select code, max(votes)
    from per_district 
    group by code
) 
order by v.name

--