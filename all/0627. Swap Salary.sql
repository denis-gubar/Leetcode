# Write your MySQL query statement below
update salary set sex = substr('fm', instr('mf', sex), 1);