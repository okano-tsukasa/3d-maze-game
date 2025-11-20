# 3D迷路ゲーム

C言語とraylibで作られたシンプルな一人称視点の3D迷路ゲームです。

![ゲームスクリーンショット](https://via.placeholder.com/800x600.png?text=3D+Maze+Game+Screenshot)

## 概要

このゲームは、一人称視点で迷路を進んでゴールを目指す教育的な3D迷路ゲームです。raylibライブラリを使用した基本的な3Dグラフィックスプログラミングのデモンストレーションとなっています。

## 特徴

- 一人称視点の3D表示
- WASDキーによる移動操作
- マウスによるカメラ回転
- ゴール到達判定システム
- シンプルでクリーンなUI
- 軽量（実行ファイル約135KB）

## スクリーンショット

(screenshots/gameplay.png)


## 必要環境

### 実行に必要なもの
- Windows 10/11
- OpenGL 3.3対応GPU
- raylib DLL（MSYS2インストール時に含まれます）

### ビルドに必要なもの
- Windows 10/11
- MSYS2
- GCCコンパイラ（15.2.0以降）
- raylibライブラリ

## インストール方法

### 方法1: ビルド済みバイナリをダウンロード（近日公開予定）

1. releasesページから`maze_game.exe`をダウンロード
2. ダブルクリックして実行

### 方法2: ソースからビルド

1. MSYS2をインストール：[https://www.msys2.org/](https://www.msys2.org/)

2. MSYS2 UCRT64ターミナルを開き、依存関係をインストール：
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-raylib
```

3. リポジトリをクローン：
```bash
git clone https://github.com/yourusername/3d-maze-game.git
cd 3d-maze-game
```

4. ゲームをビルド：
```bash
gcc -std=c99 -Wall -O2 -I/c/msys64/ucrt64/include \
    -o maze_game.exe src/main.c \
    -L/c/msys64/ucrt64/lib -lraylib -lopengl32 -lgdi32 -lwinmm
```

5. ゲームを実行：
```bash
./maze_game.exe
```

## 操作方法

| キー/操作 | 機能 |
|----------|------|
| `W` | 前進 |
| `S` | 後退 |
| `A` | 左移動 |
| `D` | 右移動 |
| `マウス` | 視点移動 |
| `ESC` | ゲーム終了 |

## 遊び方

1. `maze_game.exe`を起動
2. WASDキーで迷路内を移動
3. マウスで周囲を見回す
4. 緑色の立方体（ゴール）を見つけて迷路をクリア
5. ESCキーで終了

## プロジェクト構成

```
3d-maze-game/
├── docs/
│   ├── 要件定義書.txt          # 要件定義ドキュメント
│   ├── 設計書.txt              # 設計ドキュメント
│   ├── 動作テスト手順書.txt    # テスト手順
│   └── テスト結果レポート.txt  # テスト結果
├── src/
│   └── main.c                  # メインソースコード
├── tests/                      # テストディレクトリ
├── Makefile                    # ビルド設定
├── README.md                   # このファイル
└── LICENSE                     # ライセンスファイル

```

## 技術詳細

- **言語**: C（C99標準）
- **グラフィックスライブラリ**: raylib
- **コンパイラ**: GCC
- **プラットフォーム**: Windows（軽微な変更でLinux/macOSにも移植可能）
- **迷路サイズ**: 10x10グリッド
- **目標FPS**: 60
- **ウィンドウサイズ**: 800x600ピクセル

## 開発

### Makeでのビルド

`make`がインストールされている場合：

```bash
make all    # ゲームをビルド
make run    # ビルドして実行
make clean  # ビルド成果物をクリーンアップ
make help   # ヘルプを表示
```

### コード構造

シンプルさのため、ゲームは単一ファイル（`src/main.c`）で実装されています：

- 迷路データ: 2次元整数配列（1=壁、0=通路）
- カメラ: raylibのCamera3Dを使用した一人称視点
- ゲームループ: 標準的な初期化-更新-描画パターン
- ゴール判定: 距離ベースの計算

## 既知の制約事項

- 衝突判定が簡易実装（壁を通り抜けることがあります）
- マウス感度が固定
- 単一の迷路レイアウト（レベル選択なし）
- サウンドエフェクトなし

## 今後の改善案

- [ ] 衝突判定の改善
- [ ] 複数の迷路レベル
- [ ] マウス感度の調整機能
- [ ] タイマーとスコアシステム
- [ ] サウンドエフェクト
- [ ] ミニマップ表示
- [ ] 外部迷路ファイルの読み込み

## コントリビューション

コントリビューションを歓迎します！IssueやPull Requestをお気軽に送ってください。

1. リポジトリをフォーク
2. フィーチャーブランチを作成（`git checkout -b feature/AmazingFeature`）
3. 変更をコミット（`git commit -m 'Add some AmazingFeature'`）
4. ブランチにプッシュ（`git push origin feature/AmazingFeature`）
5. Pull Requestを開く

## ライセンス

このプロジェクトはMITライセンスの下で公開されています。詳細は[LICENSE](LICENSE)ファイルをご覧ください。

## 謝辞

- [raylib](https://www.raylib.com/) - 素晴らしいゲーム開発ライブラリ
- [MSYS2](https://www.msys2.org/) - 開発環境

## 作者

Claude Codeで作成

## サポート

問題が発生した場合や質問がある場合：
- GitHubでIssueを開く
- `docs/`フォルダ内のドキュメントを確認

## 変更履歴

### バージョン 1.0（2025-11-20）
- 初回リリース
- 基本的な3D迷路ナビゲーション
- 一人称視点操作
- ゴール到達判定システム

---

**迷路を楽しんでください！**
