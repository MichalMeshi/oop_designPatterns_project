מבוא לתכנות מונחה עצמים
פרויקט גמר
מגישות: פנינה שוס. ת"ז: 207256215
מיכל משי זהב. ת"ז: 324102037
בפרויקט זה מימשנו את משחק Xonix  "כובש שטחים", תוך שימוש בספרית SFML.

הערה: כדאי לפתוח את הרידמי לא בתוך הויזואל כדי שיהיה קריא.

המחלקות בתוכנית ותפקידן:
AddTimeGift
מתנה שמוסיפה חיים. יורשת ממחלקת Gift
Animation
מחלקה המנהלת את האנימציות בפרויקט.
BackSoundCommand
פקודה של ניהול מוזיקת הרקע בתוכנית. יורשת מ Command
Board
מחלקה שאחראית על כל הקשור ללוח המשחק.
CanMoveToPlace
מחלקה האחראית על הרשאות תזוזה של האויבים. (משמשת עבור Strategy )
CollisionHandling
מחלקה המנהלת את ההתנגשויות במשחק. (משתמשת ב MultyMethod)
Command
מחלקת אב לכל הפקודות של תפריט. (Command design pattern)
Controller
מחלקה המנהלת את המשחק.
Display
מחלקה העוטפת תמונות ואחראית לכל הפעולות הקשורות בהן.
DynamicObj
מחלקה שממנה יורשים כל האוביקטים התזוזתיים במשחק.
Enemies
מחלקת האויבים של המשחק.
EnemyFactory
מחלקה היוצרת את האויבים ( Factory pattern)
FreezeEnemiesGift
מתנה שמקפיאה את האויבים שבלוח.  יורשת מ Gift
GameController
מחלקה המפעילה את המשחק ומנהלת את השלבים שלו.
Gift
מחלקה שממנה יורשות כל המתנות.
GiftFactory
מחלקה המיצרת מתנה בצורה מוגרלת. (Factory design) 
Graphics
מחלקת סינגלטון, בה נמצאים כל הטקסטורים הסאונדים וכו'.
ImmunePlayer
מחלקה היורשת מ player , זהו שחקן מחוסן שנוצר לזמן מוגבל בעקבות התנגשות במתנה שנותנת חסינות.
ImmunetyGift
המתנה שעושה את השחקן מחוסן לזמן מוגבל. (יורשת מ Gift)
InfoOfLevel
מחלקה בה שמורים הנתונים עבור כל שלב.
InformationDisplay
מחלקה בה נמצא כל הקשור לתפריט המופיע על הלוח במהלך כל המשחק.
KillEnemyGift
מתנה הגורמת לשחקן להיות שחקן הורג, ולהרוג את כל האויבים שהוא מתנגש איתם. (יורשת מ Gift)
KillingPlayer
מחלקה היורשת מ Player . זהו שחקן הורג לזמן מוגבל, בעקבות התנגשות במתנה לעיל.
Level
מחלקה המנהלת שלב נוכחי במשחק.
LifeGift
יורשת מ Gift , מתנה המוסיפה חיים.
Menu
ממחלקה זו יורשים כל תפריטי המשחק . (Command)
Move
ממחלקה זו יורשות מחלקות התזוזה (Strategy) 
MoveEverywhere
מחלקה האחראית על תזוזה בכל אריחי הלוח. יורשת מ CanMoveToPlace 
MoveToBlocked
מחלקה האחראית על תזוזה רק על האריחים החסומים בלוח. יורשת מ CanMoveToPlace 
MoveToUnBlocked
מחלקה האחראית על תזוזה רק על האריחים שאינם חסומים בלוח. יורשת מ CanMoveToPlace 
NewGameCommand
פקודת הפעלת המשחק. יורשת מ Command
NoiseCommand
פקודת ניהול השמע של צלילי הרקע במשחק. יורשת מ Command
Object
מחלקה שממנה יורשים כל האויביקטים במשחק.
Player
המחלקה של השחקן.
RandomMove
המחלקה האחראית על תזוזה רנדומלית. יורשת מ Move
SettingsCommand
פקודת תצוגת ההגדרות. יורשת מ Command
SettingsMenu
תפריט ההגדרות. יורשת מ Menu
ShowInstructionsCommand
פקודת תצוגת הוראות המשחק. יורשת מ Command
SimpleMove
מחלקה האחראית על תזוזה פשוטה על הלוח. יורשת מ Move
SmartMove
מחלקה האחראית על תזוזה חכמה הרודפת אחר השחקן. יורשת מ Move
StartMenu
התפריט ההתחלתי, יורשת מ Menu
StaticObj
מחלקה שממנה יורשים כל האוביקטים הסטטיים במשחק. יורשת מ Object
TerritoryEater
אויב שיורש מ Enemies. הוא אויב מיוחד שאוכל שטחים כבושים והופך אותם לריקים.


שמות הקבצים:

קבצים של חתימות הפונקציות, הבנאים ושדות המחלקה:
   
AddTimeGift.h
Animation.h
BackSoundCommand.h
Board.h
CanMoveToPlace.h
CollisionHandling.h
Command.h
Controller.h
Display.h
DynamicObj.h
Enemies.h
EnemyFactory.h
FreezeEnemiesGift.h
GameController.h
Gift.h
GiftFactory.h
Graphics.h
ImmunePlayer.h
ImmunetyGift.h
InfoOfLevel.h
InformationDisplay.h
KillEnemyGift.h
KillingPlayer.h
Level.h
LifeGift.h
Menu.h
Move.h
MoveEverywhere.h
MoveToBlocked.h
MoveToUnBlocked.h
NewGameCommand.h
NoiseCommand.h
Object.h
Player.h
RandomMove.h
SettingsCommand.h
SettingsMenu.h
ShowInstructionsCommand.h
SimpleMove.h
SmartMove.h
StartMenu.h
StaticObj.h
TerritoryEater.h
Utilities.h
בקובץ זה נמצאים כל הקונסטים וenumים שהשתמשנו בתכנית.



קבצים של מימוש הפונקציות והבנאים של המחלקה:
AddTimeGift.cpp
Animation.cpp
BackSoundCommand.cpp
Board.cpp
CollisionHandling.cpp
Controller.cpp
Display.cpp
Enemies.cpp
EnemyFactory.cpp
FreezeEnemiesGift.cpp
GameController.cpp
Gift.cpp
GiftFactory.cpp
Graphics.cpp
ImmunetyGift.cpp
InfoOfLevel.cpp
InformationDisplay.cpp
KillEnemyGift.cpp
Level.cpp
LifeGift.cpp
Menu.cpp
Move.cpp
MoveEverywhere.cpp
MoveToBlocked.cpp
MoveToUnBlocked.cpp
NoiseCommand.cpp
Player.cpp
RandomMove.cpp
SettingsCommand.cpp
SettingsMenu.cpp
ShowInstructionsCommand.cpp
SimpleMove.cpp
SmartMove.cpp
StartMenu.cpp
TerritoryEater.cpp

מבני נתונים עיקריים ותפקידיהם:
השתמשנו בוקטורים של uniqe_ptr עבור האויבים והמתנות.
השתמשנו בוקטור על וקטור עבור המטריצה של הלוח.

באגים נפוצים:
אין באגים בתוכנית!

אלגוריתמים הראויים לציון:
התשמשנו בכמה design patterns:
השתמשנו ב MultyMethod לניהול ההתנגשויות.
השתמשנו בfactory+strategy עבור בנית האויבים, שבהם יש מצביע עבור סוג התזוזה. כאשר במחלקה של התזוזה יש מצביע נוסף עבור סוג המשבצות שמותר לאויב לזוז אליהם. (strategy בתוך strategy ) 
השתמשנו ב factory עבור בנית מתנות מוגרלות במהלך המשחק.
השתמשנו ב Command בתוך Command עבור התפריט הראשוני, שבתוכו יש תפריט משני של הגדרות.
השתמשנו ב singleton עבור מחלקת Graphics שבה נמצאים כל הTextures, Sounds חלון המשחק וכו'. ככה כולם מכירים אותה ויכולים לקבל ממנה בקלות את מה שצריכים.

בנוסף השתמשנו באלגוריתם הרקורסיבי : FloodFIll  עבור צביעת השטח שנכבש ע"י השחקן. (צביעת שטח היא בתנאי שאין בשטח הכלוא אויב שהוא כדור)

הערות כלליות:
קל מאוד לשדרג את המשחק ולהוסיף שלבים.
ניתן בקלות ליצור עוד סוג של אויבים - פשוט להוסיף עוד מחלקה של תזוזה ולשלב עם אחת המחלקות של "על אילו משבצות מותר ללכת", ולייצר ב facrory את האויב החדש.
כללי המשחק:
מטרת השחקן לכבוש את השטח המתבקש בכל שלב.
יש לו מספר חיים, כאשר הם נגמרים והשחקן נפסל המשחק נגמר.
הסיבות שמורידות לשחקן חיים:
 אם הוא נפגש באויב (חוץ מהאוכל שטחים) .
אם הוא זז על מקום שהוא באמצע לכבוש (מקום שמסומן בעיגול)
אם נגמר הזמן.

האויבים במשחק:
אויב טיפש - מטייל על הלוח .על כל סוגי השטחים (כבוש ולא כבוש)
אויב חכם - רודף אחרי השחקן. מטייל על כל הלוח .
כדור- תפקידו לטייל רק בשטח שאינו כבוש. אם השחקן מקיף שטח שמוכל בו כדור השטח הכלוא אינו נכבש.
אוכל שטחים - אוכל את השטחים שנכבשו ע"י השחקן.

סוגי מתנות:
תוספת חיים
תוספת זמן
הקפאת האויבים למשך כמה שניות
מתנה שהופכת את השחקן לחסין למשך כמה שניות
מתנה שהופכת את השחקן להרוג את כל האויבים שנתקל בהם (למעט האוכל שטחים שאותו לא ניתן להרוג) למשך כמה שניות.
