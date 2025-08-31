select q.query_name,
    round( (sum(q.rating/q.position) / count(q.result))  ,2) as quality,
    round ( ( 
        ( 
            select sum(q.rating < 3) 
        )
        *100/count(q.result)) ,2) as poor_query_percentage
from Queries q
group by(q.query_name);