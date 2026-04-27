import pandas as pd

def average_selling_price(prices: pd.DataFrame, units_sold: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(prices, units_sold, on = 'product_id', how = 'left')
    mask = ((df['purchase_date'] >= df['start_date']) &
            (df['purchase_date'] <= df['end_date'])
            )
    df['valid'] = 0
    df['total_sum'] = 0.0
    df.loc[mask, 'valid'] = df['units']
    df.loc[mask, 'total_sum'] = df['price'] * df['units']

    df = df.groupby('product_id').agg(
        total_price = ('total_sum', 'sum'),
        total_units = ('valid', 'sum')
    ).reset_index()

    df['average_price'] = (df['total_price'] / df['total_units']).fillna(0).round(2)
    return df[['product_id', 'average_price']]