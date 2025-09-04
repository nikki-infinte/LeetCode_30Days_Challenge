select u.activity_date as day , count(distinct(user_id)) as active_users
from Activity u
where u.activity_date between '2019-06-28' and '2019-07-27'
group by u.activity_date
;