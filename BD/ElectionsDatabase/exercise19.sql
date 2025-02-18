/*
. What	are	the	municipalities	of	the	same	district	with	the	same	number	of	parishes?	List	
the	code	of	 the	district,	 the	names	of	 the	municipalities	and	 the	common	number	of	
parishes,	 without	 repetitions	 such	 as	 (A,B)	 and	 (B,A).	 Order	 ascendantly	 on	 the	
district's	code,	name	of	the	first	municipality	and	name	of	the	second	municipality.
*/


with npa as (
    select p.municipality as code, count(*) as np
    from parishes p
    group by p.municipality
)



select *
from npa as p 
join municipalities m on m.code = p.code
join municipalities m1 
where m1.district = m.district
