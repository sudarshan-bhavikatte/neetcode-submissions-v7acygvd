-- Write your query below

-- users
-- account is pk

-- transactions 
-- trans_id is pk

-- output : name 	balance
-- condition : amout > 1000

select u.name, sum(t.amount) as balance
from transactions t
join users u
on t.account = u.account
group by name
having sum(t.amount) > 10000