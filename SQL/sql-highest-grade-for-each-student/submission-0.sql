-- Write your query below

-- exam_results
-- (student_id, exam_id) is pk

-- sol
-- return max(score) if mutiple return min(exam_id)

SELECT DISTINCT ON (student_id)
    student_id,
    exam_id,
    score
FROM exam_results
ORDER BY student_id, score DESC, exam_id;



