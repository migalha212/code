with results as (
    select municipality, party, sum(v.Votes) as votes
    from votings v
    join Parishes on code = parish
    where (municipality, votes) in (
        select p.municipality, max(votes)
        
    )
)


select *
from presults