select T.team_id, T.team_name, sum(points) as num_points
from (select h.team_id as team_id, h.team_name as team_name, coalesce(sum(
        case 
            when m.host_goals > m.guest_goals then 3 
            when m.host_goals = m.guest_goals then 1 
            when m.host_goals < m.guest_goals then 0
        end ),0) as points
    from matches m
    right join teams h on h.team_id = m.host_team
    group by h.team_id, h.team_name

    union all

    select g.team_id as team_id, g.team_name as team_name, coalesce(sum(
        case 
            when m.host_goals < m.guest_goals then 3 
            when m.host_goals = m.guest_goals then 1 
            when m.host_goals > m.guest_goals then 0
        end ),0) as points
    from matches m
    right join teams g on g.team_id = m.guest_team
    group by g.team_id, g.team_name
    ) T
group by team_id, team_name
order by num_points desc, team_id