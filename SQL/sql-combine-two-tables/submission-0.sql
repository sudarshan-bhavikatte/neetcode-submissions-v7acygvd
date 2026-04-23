-- Write your query below

-- person
-- person_id is pk

-- address
-- address_id is pk
-- person_id is fk

select p.first_name, p.last_name, a.city, a.state
from person p
left join address a
on p.person_id = a.person_id;
