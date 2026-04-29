-- Write your query below

-- sales
-- sale_date, fruit is pk

-- output : sale_date ,diff(apples - oranges)

-- sol
-- subqueries to find all apples sales and oranges sales
-- join them on sale_date
-- add a column as diff

select a.sale_date, (a.sold_num - o.sold_num) as diff
from (
    select sale_date, sold_num from sales where fruit = 'apples'
    ) a
join (
    select sale_date, sold_num from sales where fruit = 'oranges'
    ) o
on a.sale_date = o.sale_date