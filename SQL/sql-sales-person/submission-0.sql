-- Write your query below

select distinct S.name
from sales_person S
left join (
    select o.sales_id, c.name
    from orders o
    join company c 
    on o.com_id = c.com_id
    where c.name = 'CRIMSON'
) C
on S.sales_id = C.sales_id
where C.name is null