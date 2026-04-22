-- Write your query below

-- customers
-- id is pk

-- orders
-- id is pk
-- customer_id is fk

select name
from customers
where id not in (select c.id 
    from customers c
    join orders o
    on c.id = o.customer_id);