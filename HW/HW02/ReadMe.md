# 과제
* 학번 : 202327027 
* 이름 : 박윤하

### VCS란 무엇인가
* "Version Control System"의 약자로, 버전 관리 시스템을 의미합니다.
    소프트웨어 개발에서 코드 및 파일의 변경 내역을 추적하고 관리하는 도구입니다.
    VCS는 프로젝트의 모든 파일과 폴더에 대한 변경 사항을 기록하고, 이전 버전과의 차이를 비교하거나
    특정 시점으로 돌아갈 수 있는 기능을 제공합니다.
    VCS를 사용하면 여러 개발자가 동시에 작업하고 소스 코드를 공유할 수 있으며,
    버전 간의 충돌을 해결하고 변경 이력을 추적할 수 있습니다.
    또한 실험적인 변경 사항을 시도해 보거나 특정 버전으로 롤백하는 등의 작업도 가능합니다.

### DVCS와 VCS의 차이점
* DVCS는 **분산 구조**를 가지고 있으며, 
    각 개발자는 로컬 저장소를 가지고 작업을 하며 변경 사항을 원격 저장소에 반영할 수 있습니다.
    Git과 Mercurial이 이에 해당합니다.
    DVCS는 로컬 저장소에서 작업하기 때문에 네트워크 연결이 없이도 빠르게 변경 사항을 커밋하고
    브랜치를 생성할 수 있습니다.
    DVCS는 여러 지역 또는 지리적으로 분산된 팀이 협업하는 데 유리합니다.
    또한 DVCS는 로컬 저장소를 가지고 있기 때문에 데이터 손실의 위험이 적습니다.

* VCS는 **중앙 집중식 구조**를 가지며, 모든 파일의 이력과 변경 사항이 중앙 서버에 저장되어 
    개발자는 중앙 서버에서 소스 코드를 가져와 작업합니다.
    SVN과 CVS가 이에 해당합니다.
    VCS는 중앙 서버와의 통신이 필요하기 때문에 작업 속도가 느릴 수 있습니다.
    VCS는 중앙 서버를 통해 협업하기 때문에 여러 지역 또는 지리적으로 분산된 팀의 협업에 
    제한이 있을 수 있습니다.
    또한 VCS는 중앙 서버에만 저장되기 때문에 중앙 서버에 장애가 발생할 시 데이터 손실의 위험이 있습니다.

### GIT을 이용하여 remote repository를 생성하고 git용 bash 로 새로 initialize한 local repository랑 연결하는 과정
* 이미지 1번을 보시면 \
    $ cd / <- cd는 Change Directory(폴더 이동)입니다.
    $ cd c <- c드라이브로 이동해준 뒤 \
    $ mkdir test <- make directory(폴더 생성) test라는 이름의 폴더를 생성해주고 \
    $ cd test <- test 폴더로 이동해준 뒤 \
    $ git init <- init은 initialize의 줄임말로, 깃 초기화를 해준 뒤 \
    $ git branch -m master main <- 브랜치명을 변경하는 명령어 입니다.

* 이미지 2번으로 넘어가서 \
    $ vi ReadMe.md <- vi는 Vim(Visual Editor Improved)의 줄임말입니다. 리드미 파일을 만들어준 뒤 \
    $ git status <- git status는 현재 작업 디렉토리의 상태를 보여주는 명령어입니다. \
    $ git add . <- git add는 깃에서 파일을 추가하는 데 사용됩니다. add 뒤에 .은 모든 파일을 추가해준다는 것입니다. \
    $ git status <- 전과 달리 ReadMe.md 파일이 추가되었다는 것을 볼 수 있습니다. \
    $ git commit <- 변경 사항을 로컬 저장소에 기록하는 명령어입니다. \
    $ git remote add origin 주소 <- origin은 원격 저장소의 별칭이고, 주소는 자신의 깃허브 주소 복붙하면 됩니다.

* 이미지 3번으로 넘어가서 \
    $ git push <- 로컬 저장소의 변경 사항을 원격 저장소로 업로드하는 데 사용됩니다. \
    $ git push --set-upstream origin main <- 현재 로컬 브랜치를 원격 저장소의 지정된 브랜치로 푸시하도록 설정합니다. 'set-upstream' 옵션을 사용하여 해당 로컬 브랜치가 원격 브랜치와 연결되도록 설정하였습니다.

### .gitignore 사용법과 작성방식 및 내용
* 사용법 \
새로운 .gitignore 파일 생성: 프로젝트 루트 디렉토리에 gitignore 파일을 만듭니다. 만약 이미 gitignore 파일이 있다면 그 파일을 엽니다.
원하는 내용 추가: gitignore 파일에는 Git이 추적하지 않아야 하는 파일 및 디렉토리의 패턴을 추가합니다. 예를 들어, Visual Studio 프로젝트의 경우 Visual Studio에서 생성하는 빌드 결과물, 임시 파일 등을 추가할 수 있습니다.
패턴 추가 방법: 파일이나 디렉토리 이름을 직접 작성합니다. 예를 들어, bin/ 또는 .suo. 와일드카드()를 사용하여 패턴을 작성할 수 있습니다. 예를 들어, *.log는 확장자가 .log인 모든 파일을 무시합니다.
하위 디렉토리를 지정하기 위해 /를 사용할 수 있습니다. 예를 들어, **/node_modules/는 모든 하위 디렉토리에 있는 node_modules 폴더를 무시 합니다.
주석 추가: 필요에 따라 주석을 추가하여 다른 개발자가 .gitignore 파일을 이해하도록 돕습니다.
저장 및 커밋: .gitignore 파일을 저장하고 Git 저장소에 커밋합니다. 이제 Git은 .gitignore에 명시된 파일 및 디렉토리를 무시합니다.

* 작성방식 \
파일 무시: 특정 파일을 무시하려면 해당 파일의 이름을 .gitignore 파일에 적습니다. 예를 들어, example.txt를 무시하려면 example.txt라고 .gitignore 파일에 추가하면 됩니다.
와일드카드: 와일드카드(*)는 여러 파일을 한 번에 지정하는 데 사용됩니다. 예를 들어, *log는 모든 확장자가 .log인 파일을 무시합니다. *은 모든 것을 나타냅니다. 따라서 *만 사용하면 모든 파일을 무시합니다.
디렉토리 무시: 디렉토리를 무시하려면 해당 디렉토리의 이름을 .gitignore 파일에 추가합니다. 예를 들어, logs/는 logs 디렉토리와 그 하위 디렉 토리를 모두 무시합니다.
주석: 주석은 #으로 시작합니다. 주석은 .gitignore 파일 내에서 설명을 추가하는 데 사용됩니다. 주석 뒤의 모든 내용은 Git에 의해 무시됩니다.
부분 경로 지정: 패턴은 부분 경로를 지정할 수 있습니다. 예를 들어, **/logs/는 모든 하위 디렉토리에 있는 logs 디렉토리를 무시합니다.
반전 패턴: 느낌표(!)는 반전 패턴을 나타냅니다. 즉, 특정 파일이나 디렉토리를 무시하지 않도록 할 수 있습니다. 예를 들어, !important.log는 important.log 파일을 무시하지 않습니다.

* gitignore 내용 조사 \
*rsuser, *.suo, *user, userosscache, stn.docstates: 사용자별 파일이나 Visual Studio 솔루션 상태 파일 등을 무시합니다.
.userprefs: MonoDevelop/Kamarin Studio의 사용자 설정 파일을 무시합니다.
mono_crash.: Mono 개발 환경에서 발생하는 크래시 덤프 파일을 무시합니다.
[Dd]lebug/,[Rr]jelease/, x64/, ×86/, [Ww][li][Nn]/32/, [Aa][Rr][Mm]/, [Aa][Rr][Mm]64/,  bld/.[Bb]in/, [Oo]bj/, [Ll]og/, [Ll]ogs/: 빌드 결과물과 관련된 디렉토리들을 무시합니다.
.vs/: Visual Studio 설정 디렉토리를 무시합니다.
Generated\ Files/: Visual Studio 2017에서 자동 생성되는 파일을 무시합니다.
[Tt]est[Rr]esult/, [Bb]uild[Ll]og.: 테스트 결과 및 빌드 로그 파일을 무시합니다.
.VisualState.xml, TestResult.xml, nunit-.xml: NUnit 테스트 결과 파일을 무시합니다.
[Dd]ebugPS/, [Rr]eleasePS/, dlldata.c: ATL 프로젝트의 빌드 결과물 및 ATL 빌드 스크립트 파일을 무시합니다.
BenchmarkDotNet.Artifacts/: BenchmarkDotNet 결과물을 무시합니다.
project.lock.json, project.fragment.lock.json, artifacts/: .NET Core 프로젝트 관련 파일을 무시합니다.
ScaffoldingReadMe.txt: ASP.NET Scaffolding의 README 파일을 무시합니다.
StyleCopReport.xml: StyleCop 리포트 파일을 무시합니다.
*_i.c, *_p.c, *_h.h, *.ilk, *.meta, *.obj, *.iobj, *.pch, *.pdb, *.ipdb, *.pgc, *.pgd, *.rsp, *.sbr, *.tlb, *.tli, *.tlh, *.tmp, *.tmp_proj, *_wpftmp.csproj, *.log,
*.tlog, *.vspscc, *.vssscc, .builds, *pidb, *svclog,.scc: Visual Studio 에서 생성되는 빌드 및 임시 파일들을 무시합니다.
_Chutzpah: Chutzpah 테스트 파일들을 무시합니다.
ipch/, *.aps, *.ncb, *.opendb, *.opensdf, *.sdf, *.cachefile, *.VC.db, *.VC.VC.opendb: Visual C++ 관련 캐시 파일들을 무시합니다.
*.psess, *.vsp, *.vspx, *.sap: Visual Studio 프로파일러 파일들을 무시합니다.
*.e2e: Visual Studio 추적 파일들을 무시합니다.
$tf/: TFS 2012 Local Workspace 파일들을 무시합니다.
*.gpState: Guidance Automation Toolkit 상태 파일을 무시합니다.

### ReadMe.md 파일에 사용된 Mark Down 표기법
* 헤더는 '#' 뒤에 내용을 작성하면 되고 '#'을 1~6개 사용하냐에 따라 크기가 달라집니다.

* 목록은 '1.', '-', '*' 뒤에 내용 작성하는 것입니다.

* 들여쓰기는 '>' 뒤에 내용 작성하는 것입니다.

* 코드 블럭은 '`'을 3번 연속 입력하는 것입니다.

* 수평선은 '-', '*', '_'을 3개 이상 입력하여 추가할 수 있습니다.

* 링크는 [링크 이름]과 (URL)을 붙여서 작성하는 것입니다. \
ex) [네이버](https://www.naver.com/)

* 이미지는 ![대체 텍스트]와 (이미지 URL)을 붙여서 작성하는 것입니다. \
ex) \
![에비츄](https://search.pstatic.net/common/?src=http%3A%2F%2Fblogfiles.naver.net%2F20140926_79%2Fcocogirls204_1411722886778kY5sR_JPEG%2F%25B1%25CD%25BF%25A9%25BF%25EE_%25C2%25A9%252C_%25BF%25A1%25BA%25F1%25C3%25F2_%25C2%25A9_%25B8%25F0%25C0%25BD4.jpg&type=ff332_332)

* 강조는 '*' 1개, 2개, 3개, '~~' 앞에 기호들을 사용한 후 내용을 작성하고 또 뒤에 같은 기호로 덮어주면 됩니다. \
ex) \
*이탤릭체* \
**굵은체** \
***굵은 이탤릭체*** \
~~취소선~~