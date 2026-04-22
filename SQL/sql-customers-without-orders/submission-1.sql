-- Write your query below

-- customers
-- id is pk

-- orders
-- id is pk
-- customer_id is fk

SELECT name
FROM customers
WHERE id NOT IN (SELECT customer_id FROM orders);
