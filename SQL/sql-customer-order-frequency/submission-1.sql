-- Write your query below

-- customers
-- customeer_id is pk

-- product
-- product_id is pk

-- orders
-- order_id is pk

-- output : customer_id 	name
-- where money spent on both june 2020 and july 2020 is >= 100

-- sol:
-- join o on p
-- filter order_date and find the total sum spent and filter having grater them 100
-- join on c

select T.customer_id, c.name
from (
    select o.customer_id 
    from orders o
    join product p on o.product_id = p.product_id
    where o.order_date between '2020-06-01' and '2020-07-31' 
    group by o.customer_id, extract(month from o.order_date)
    having sum(p.price * o.quantity) >= 100
    ) T
join customers c on T.customer_id = c.customer_id
group by T.customer_id, c.name
having count(T.customer_id) = 2