import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    views['id'] = views.loc[views['author_id'] == views['viewer_id'], 'author_id'].drop_duplicates().fillna(0)
    return views.loc[views['id'] != 0, ['id']].sort_values(by = 'id')