-- Write your query below

-- calls 
-- no pk, contains duplicates

-- output : person1 	person2 	call_count 	total_duration
-- call_count = no. of calls
-- total_duration = total time of calls
-- output should not contain duplicates like 1 -> 2 and 2 -> 1

-- sol :
-- try : odering the lower id as from_id and larger as to_id
-- for a pair of 2 ids, the ordering will always be the same


select 
    case when from_id < to_id then from_id else to_id end as person1,
    case when from_id > to_id then from_id else to_id end as person2,
    count(*) as call_count,
    sum(duration) as total_duration
from calls
group by person1, person2

