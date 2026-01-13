## Embedded Linux
---

### 本地项目关联 Git
1. 安装git
```bash
apt update && apt install git -y

git --version
```

2. Git 全局基础配置
```bash
# 配置Github用户名
git config --global user.name "你的Github用户名"
# 配置Github注册邮箱（必须一致）
git config --global user.email "你的Github注册邮箱@xxx.com"

git config --list
```

3. 配置 SSH 密钥
```bash
# 生成 SSH 密钥对
ssh-keygen -t rsa -b 4096 -C "你的Github注册邮箱@xxx.com"

ls -al ~/.ssh

# 查看并复制「完整公钥内容」
cat ~/.ssh/id_rsa.pub

# 在 Github 网页端配置公钥 
# 头像Settings -> SSH and GPG keys -> New SSH key

# 测试 SSH 连接 Github 是否成功
ssh -T git@github.com
```

4. 创建 Github 远程空仓库

5.  本地项目 初始化 Git + 推送至 Github
```bash
# 1. 进入本地项目根目录
cd /home/kant/EmbeddedLinux

# 2. 初始化本地 Git 仓库
git init

# 3. 将本地所有文件加入 Git 暂存区
git add .

# 4. 将暂存区文件提交到本地 Git 仓库
git commit -m "文字说明"

# 5. 将本地仓库 关联 Github 远程仓库
git remote add origin git@github.com:用户名/xxxx.git

# 6. 重命名本地主分支
git branch -M main

# 7. 本地代码推送到 Github 远程仓库
git push -u origin main
```
---
```bash
本地项目 → git init 初始化 → git add . 暂存 → git commit 本地提交 → git remote add 关联远程 → git push 推送到Github
```
- 高频核心命令
```bash
# 1. 写完代码/修改文件后，把所有变更加入暂存区
git add .

# 2. 提交到本地仓库，写清楚修改备注
git commit -m "修改：修复xxx驱动bug / 新增：添加xxx模块代码"

# 3. 推送到Github远程仓库
git push
```

- 基础查询命令
```bash
# 查看本地文件状态（哪些文件修改/新增/未追踪，最常用）
git status

# 查看本地所有分支（*号标记当前所在分支）
git branch

# 查看所有提交历史（版本记录，按时间倒序排列）
git log

# 查看本地关联的远程仓库地址
git remote -v
```
---