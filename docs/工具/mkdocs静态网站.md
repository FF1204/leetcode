# mkdocs搭建博客

使用mkdocs搭建个人博客系统，实现知识管理。
实现的功能：
1. 根据文件夹结构自动生成多级目录(每个文件一个标题，显示在左侧)
2. 根据文章内容自动生成文章目录(显示在右侧)
3. 忽略程序源代码文件(文件夹还是可以使用的vscode工程)
4. 自动导出所有md文件为一个PDF文档，带目录。
5. github托管源码， travis自动构建，在线编辑

## 安装

1. 安装python, pip
2. pip install mkdocs

## 使用

创建配置文件 mkdocs.yml

```shell
site_name: FEIFEI的个人博客
repo_name: FF1204/leetcode
repo_url: https://github.com/FF1204/leetcode
markdown_extensions:
  - markdown.extensions.admonition
  - pymdownx.tabbed
  - codehilite:
      guess_lang: false
      linenums: true
  - markdown.extensions.toc:
      permalink: true
theme: 
    name: material 
    language: zh
    palette:
        primary: teal
        accent: indigo
plugins:
  - search
  - add-number:
        strict_mode: False
        order: 1
        excludes:
            - sql/
            - command/rsync
        includes:
            - sql/MySQL
  - awesome-pages
  - mkpdfs
  - exclude
```

安装配置文件中提到的 material 主题，add-number，awesome-pages，mkpdfs， exclude插件

在该文件对应的目录中运行 mkdocs serve, 启动本地服务器，就可以在localhost:8000 看到网站效果。

## 自动部署

把 .travis.yml 添加到博客根目录，在travis网站上创建项目并关联github仓库。

```shell
dist: bionic
language: python
python:
-  3.7
install:
  - sudo apt-get install build-essential python3-dev python3-pip python3-setuptools python3-wheel python3-cffi libcairo2 libpango-1.0-0 libpangocairo-1.0-0 libgdk-pixbuf2.0-0 libffi-dev shared-mime-info
  - pip install mkdocs
  - pip install mkdocs-material
  - pip install mkdocs-awesome-pages-plugin
  # mkpdfs-mkdocs 存在BUG暂未修复，使用自己修复之后的版本
  #- pip3 install mkpdfs-mkdocs
  - pip install -e git+https://github.com/FF1204/mkpdfs-mkdocs-plugin.git#egg=mkpdfs-mkdocs-plugin
  - pip3 install mkdocs-add-number-plugin
script:
  - mkdocs build --clean
after_success:  |
  if [ -n "$GITHUB_API_KEY" ]; then
    cd "$TRAVIS_BUILD_DIR"
    cd site
    git init
    git add .
    git -c user.name=$GITHUB_NAME -c user.email=$GITHUB_EMAIL commit -m "Auto Deployment"
    git push -f -q https://$GITHUB_NAME:$GITHUB_API_KEY@github.com/FF1204/leetcode.git master:gh-pages
    cd "$TRAVIS_BUILD_DIR"
  fi
```

其中， `GITHUB_NAME`， `GITHUB_EMAIL`， `GITHUB_API_KEY`是在travis网站对应项目中填写的自己的gihub密钥。`TRAVIS_BUILD_DIR`是travis内置的变量，表示配置文件所在的路径。


