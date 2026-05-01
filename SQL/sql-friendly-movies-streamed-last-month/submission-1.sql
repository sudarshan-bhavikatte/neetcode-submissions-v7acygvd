-- Write your query below

-- tv_program
-- program_date and content_id forms the primary key

-- content
-- The content_id column is the primary key
-- kids_content is 'Y' or 'N'
-- content_type is 'Movies', 'Series', or other type

-- output : title
-- condition : movies, kid-frindly and june 2020


select distinct c.title
from tv_program t
join content c on t.content_id = c.content_id
where (extract(month from t.program_date::date) = 6 
    and extract(year from t.program_date::date) = 2020) 
    and c.kids_content = 'Y'
    and c.content_type = 'Movies'
