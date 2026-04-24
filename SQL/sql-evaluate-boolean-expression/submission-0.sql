-- Write your query below

-- variables
-- name is pk

-- expressions
-- (left_operand, operator, right_operand) is ck
-- operator enum = [<, > , =]
-- left_operand , right_operand are ref to variable name (fk)


select e.left_operand, e.operator, e.right_operand,
    case operator
        when '<' then v1.value < v2.value
        when '>' then v1.value > v2.value
        when '=' then v1.value = v2.value
    end as value
from expressions e
join variables v1 on v1.name = e.left_operand
join variables v2 on v2.name = e.right_operand