-- Write your query below

-- activity
-- player_id and event_date forms the primary key

select player_id, min(event_date) as first_login
from activity
group by player_id