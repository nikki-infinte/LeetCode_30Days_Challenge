SELECT a.machine_id , round(avg(a2.timestamp - a.timestamp),3)as processing_time
FROM Activity a
Join Activity a2
on a.machine_id = a2.machine_id and a.process_id = a2.process_id and a.activity_type = 'start' and a2.activity_type = 'end'
group by a.machine_id;