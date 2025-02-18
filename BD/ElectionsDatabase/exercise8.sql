select p.acronym, p.designation
from Parties p
where p.acronym not in (select l.Party from
                        Lists l join Districts d 
                        on d.name = 'Lisboa' 
                        and l.District = d.code)