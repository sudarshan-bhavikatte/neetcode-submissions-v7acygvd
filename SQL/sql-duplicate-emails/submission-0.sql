-- Write your query below

-- person
-- id is pk

select email
from person
group by email
having count(*) > 1;