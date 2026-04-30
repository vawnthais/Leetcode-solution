import pandas as pd
import numpy as np
def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees.loc[(employees['employee_id'] % 2 == 1) &
                                    ~employees['name'].str.contains('^M'), 'salary']
    employees = employees.fillna(0)
    employees = employees.sort_values(by = 'employee_id')
    return employees[['employee_id', 'bonus']]