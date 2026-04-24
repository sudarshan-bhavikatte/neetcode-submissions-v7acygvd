-- Write your query below

-- orders
-- order_number column is the primary key

select customer_number
from orders
group by customer_number
order by count(customer_number) desc
limit 1



