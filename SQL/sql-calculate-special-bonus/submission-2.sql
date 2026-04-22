-- Write your query below

-- employees
-- employee_id is pk

select employee_id, 
    case employee_id % 2
        when 0 then 0
        when 1 then (case when name not like 'M%' then salary else 0 end) 
    end as bonus
from employees
order by employee_id asc;