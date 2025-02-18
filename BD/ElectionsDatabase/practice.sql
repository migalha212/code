-- 8. What	were	the	parties	that	did	not	compete	in	the	district	of	Lisboa?	List	the	acronym	
-- and	designation,	in	increasing	order	of	the	acronym.

SELECT	 ACRONYM,	 DESIGNATION
FROM PARTIES P
WHERE	 ACRONYM	 NOT	 IN	 (
SELECT PARTY
FROM	 LISTS	 L,	 DISTRICTS	 D
WHERE	 L.DISTRICT=D.CODE
AND D.NAME = 'Lisboa'
)
ORDER BY ACRONYM;