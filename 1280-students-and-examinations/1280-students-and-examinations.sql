# Write your MySQL query statement below
select Students.student_id, 
        Students.student_name, 
        Subjects.subject_name,
        count(Examinations.subject_name) as attended_exams
from Students
    cross join Subjects
    left join Examinations 
        on Students.student_id = Examinations.student_id
        and Examinations.subject_name = Subjects.subject_name
group by Students.student_id,Students.student_name, Subjects.subject_name
order by student_id, student_name