import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(customers, orders, left_on = 'id', right_on = 'customerId', how = 'left')
    result = df.loc[df['customerId'].isna(), ['name']]
    result = result.rename(columns={'name': 'Customers'})
    return result
    