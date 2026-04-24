-- Write your query below

-- warehouse 
-- name and product_id is the primary key

-- products
-- product_id column is the primary key

select w.name as warehouse_name, coalesce(sum(w.units * p.width * p.length * p.height), 0) as volume
from warehouse w
left join products p 
on w.product_id = p.product_id
group by w.name

