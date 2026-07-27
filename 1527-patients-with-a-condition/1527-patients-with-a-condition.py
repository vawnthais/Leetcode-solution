import pandas as pd

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    result = patients['conditions'].str.contains(r'(^|\s)DIAB1', regex = True, na = False)
    return patients[result]