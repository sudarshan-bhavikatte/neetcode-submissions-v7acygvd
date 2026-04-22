-- Write your query below

-- customers
-- customer_id is pk

-- orders
-- order_id is pk
-- customer_id is fk

-- sol
-- find customers where c.customer_id == o.customer_id and prodct_name = A, B not C

select customer_id, customer_name
from customers
where customer_id in (
    select customer_id
    from orders
    where product_name = 'A'
    ) 
    and customer_id in (
    select customer_id
    from orders
    where product_name = 'B'
    ) 
    and customer_id not in (
    select customer_id
    from orders
    where product_name = 'C'
    )
order by customer_name; 