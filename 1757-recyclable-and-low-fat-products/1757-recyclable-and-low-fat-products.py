import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    df = products.loc[(products['low_fats'] == 'Y') & (products['recyclable'] == 'Y'), ['product_id']]
    return df
    