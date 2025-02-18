with results as(
    select v.party as party, v.votes as votes, v.parish as parish
    from votings v
    where (v.parish, v.votes) in (
        select parish, max(votes)
        from votings
        group by parish
    )
)

select m.code, m.name, r.party as PARTY
from results r 
join Parishes p on p.code = r.parish
join municipalities m on m.code = p.municipality
join Districts d on d.code = m.District
where d.name = 'Porto'
group by m.code, m.name, r.party
having count(*) = (
    select count(*)
    from Parishes x
    where x.municipality = m.code
)
    order by m.code, r.party