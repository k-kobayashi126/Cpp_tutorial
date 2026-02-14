# python 3.12が最初から入っているコンテナを作成
FROM python:3.12

# コンテナの中での作業フォルダを設定
WORKDIR /app

# requirements.txtを先にコピー (変更内なら再インストールしなくて済む)
COPY requirements.txt .

# ライブラリをインストール
RUN pip install --no-cache-dir -r requirements.txt

# ホストの"."フォルダをコンテナ内の"/app"にコピー
COPY . /app

# jupyter lab用のポートを宣言 (あくまでDocument的な意味)
EXPOSE 8888

# コンテナ起動時に実行するコマンド
# "--ip=0.0.0.0"：どのネットワークからでも受け付ける
# "--port=8888"：jupyter labはこのポートで待っているよ
# "--no-browser"：勝手にGUIのブラウザを開かないでね
# "--allow-root"]：rootユーザーにjupyter実行の許可
CMD ["jupyter", "lab", "--ip=0.0.0.0", "--port=8888", "--no-browser", "--allow-root"]