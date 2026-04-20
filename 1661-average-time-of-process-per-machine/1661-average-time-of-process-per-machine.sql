# Write your MySQL query statement below
select distinct(s1.machine_id), 
                round(avg(s1.timestamp - s2.timestamp), 3) as processing_time
from Activity s1 
    join Activity s2 
        on s1.machine_id = s2.machine_id
        and s1.process_id = s2.process_id
where s1.activity_type = "end" and s2.activity_type = "start"
group by s1.machine_id