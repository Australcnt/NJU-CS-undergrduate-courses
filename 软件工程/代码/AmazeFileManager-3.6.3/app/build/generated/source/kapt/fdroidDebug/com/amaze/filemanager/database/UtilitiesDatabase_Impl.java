package com.amaze.filemanager.database;

import androidx.room.DatabaseConfiguration;
import androidx.room.InvalidationTracker;
import androidx.room.RoomOpenHelper;
import androidx.room.RoomOpenHelper.Delegate;
import androidx.room.RoomOpenHelper.ValidationResult;
import androidx.room.util.DBUtil;
import androidx.room.util.TableInfo;
import androidx.room.util.TableInfo.Column;
import androidx.room.util.TableInfo.ForeignKey;
import androidx.room.util.TableInfo.Index;
import androidx.sqlite.db.SupportSQLiteDatabase;
import androidx.sqlite.db.SupportSQLiteOpenHelper;
import androidx.sqlite.db.SupportSQLiteOpenHelper.Callback;
import androidx.sqlite.db.SupportSQLiteOpenHelper.Configuration;
import com.amaze.filemanager.database.daos.BookmarkEntryDao;
import com.amaze.filemanager.database.daos.BookmarkEntryDao_Impl;
import com.amaze.filemanager.database.daos.GridEntryDao;
import com.amaze.filemanager.database.daos.GridEntryDao_Impl;
import com.amaze.filemanager.database.daos.HiddenEntryDao;
import com.amaze.filemanager.database.daos.HiddenEntryDao_Impl;
import com.amaze.filemanager.database.daos.HistoryEntryDao;
import com.amaze.filemanager.database.daos.HistoryEntryDao_Impl;
import com.amaze.filemanager.database.daos.ListEntryDao;
import com.amaze.filemanager.database.daos.ListEntryDao_Impl;
import com.amaze.filemanager.database.daos.SftpEntryDao;
import com.amaze.filemanager.database.daos.SftpEntryDao_Impl;
import com.amaze.filemanager.database.daos.SmbEntryDao;
import com.amaze.filemanager.database.daos.SmbEntryDao_Impl;
import java.lang.Override;
import java.lang.String;
import java.lang.SuppressWarnings;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

@SuppressWarnings({"unchecked", "deprecation"})
public final class UtilitiesDatabase_Impl extends UtilitiesDatabase {
  private volatile HiddenEntryDao _hiddenEntryDao;

  private volatile GridEntryDao _gridEntryDao;

  private volatile ListEntryDao _listEntryDao;

  private volatile HistoryEntryDao _historyEntryDao;

  private volatile BookmarkEntryDao _bookmarkEntryDao;

  private volatile SmbEntryDao _smbEntryDao;

  private volatile SftpEntryDao _sftpEntryDao;

  @Override
  protected SupportSQLiteOpenHelper createOpenHelper(DatabaseConfiguration configuration) {
    final SupportSQLiteOpenHelper.Callback _openCallback = new RoomOpenHelper(configuration, new RoomOpenHelper.Delegate(5) {
      @Override
      public void createAllTables(SupportSQLiteDatabase _db) {
        _db.execSQL("CREATE TABLE IF NOT EXISTS `bookmarks` (`_id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, `path` TEXT, `name` TEXT)");
        _db.execSQL("CREATE UNIQUE INDEX IF NOT EXISTS `bookmarks_idx` ON `bookmarks` (`name`, `path`)");
        _db.execSQL("CREATE TABLE IF NOT EXISTS `grid` (`_id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, `path` TEXT)");
        _db.execSQL("CREATE TABLE IF NOT EXISTS `hidden` (`_id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, `path` TEXT)");
        _db.execSQL("CREATE TABLE IF NOT EXISTS `history` (`_id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, `path` TEXT)");
        _db.execSQL("CREATE TABLE IF NOT EXISTS `list` (`_id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, `path` TEXT)");
        _db.execSQL("CREATE TABLE IF NOT EXISTS `smb` (`_id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, `path` TEXT, `name` TEXT)");
        _db.execSQL("CREATE TABLE IF NOT EXISTS `sftp` (`_id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, `path` TEXT, `name` TEXT, `pub_key` TEXT, `ssh_key_name` TEXT, `ssh_key` TEXT)");
        _db.execSQL("CREATE TABLE IF NOT EXISTS room_master_table (id INTEGER PRIMARY KEY,identity_hash TEXT)");
        _db.execSQL("INSERT OR REPLACE INTO room_master_table (id,identity_hash) VALUES(42, 'fd9be1eb18f13625e763342c783122da')");
      }

      @Override
      public void dropAllTables(SupportSQLiteDatabase _db) {
        _db.execSQL("DROP TABLE IF EXISTS `bookmarks`");
        _db.execSQL("DROP TABLE IF EXISTS `grid`");
        _db.execSQL("DROP TABLE IF EXISTS `hidden`");
        _db.execSQL("DROP TABLE IF EXISTS `history`");
        _db.execSQL("DROP TABLE IF EXISTS `list`");
        _db.execSQL("DROP TABLE IF EXISTS `smb`");
        _db.execSQL("DROP TABLE IF EXISTS `sftp`");
        if (mCallbacks != null) {
          for (int _i = 0, _size = mCallbacks.size(); _i < _size; _i++) {
            mCallbacks.get(_i).onDestructiveMigration(_db);
          }
        }
      }

      @Override
      protected void onCreate(SupportSQLiteDatabase _db) {
        if (mCallbacks != null) {
          for (int _i = 0, _size = mCallbacks.size(); _i < _size; _i++) {
            mCallbacks.get(_i).onCreate(_db);
          }
        }
      }

      @Override
      public void onOpen(SupportSQLiteDatabase _db) {
        mDatabase = _db;
        internalInitInvalidationTracker(_db);
        if (mCallbacks != null) {
          for (int _i = 0, _size = mCallbacks.size(); _i < _size; _i++) {
            mCallbacks.get(_i).onOpen(_db);
          }
        }
      }

      @Override
      public void onPreMigrate(SupportSQLiteDatabase _db) {
        DBUtil.dropFtsSyncTriggers(_db);
      }

      @Override
      public void onPostMigrate(SupportSQLiteDatabase _db) {
      }

      @Override
      protected RoomOpenHelper.ValidationResult onValidateSchema(SupportSQLiteDatabase _db) {
        final HashMap<String, TableInfo.Column> _columnsBookmarks = new HashMap<String, TableInfo.Column>(3);
        _columnsBookmarks.put("_id", new TableInfo.Column("_id", "INTEGER", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsBookmarks.put("path", new TableInfo.Column("path", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsBookmarks.put("name", new TableInfo.Column("name", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysBookmarks = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesBookmarks = new HashSet<TableInfo.Index>(1);
        _indicesBookmarks.add(new TableInfo.Index("bookmarks_idx", true, Arrays.asList("name","path")));
        final TableInfo _infoBookmarks = new TableInfo("bookmarks", _columnsBookmarks, _foreignKeysBookmarks, _indicesBookmarks);
        final TableInfo _existingBookmarks = TableInfo.read(_db, "bookmarks");
        if (! _infoBookmarks.equals(_existingBookmarks)) {
          return new RoomOpenHelper.ValidationResult(false, "bookmarks(com.amaze.filemanager.database.models.utilities.Bookmark).\n"
                  + " Expected:\n" + _infoBookmarks + "\n"
                  + " Found:\n" + _existingBookmarks);
        }
        final HashMap<String, TableInfo.Column> _columnsGrid = new HashMap<String, TableInfo.Column>(2);
        _columnsGrid.put("_id", new TableInfo.Column("_id", "INTEGER", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsGrid.put("path", new TableInfo.Column("path", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysGrid = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesGrid = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoGrid = new TableInfo("grid", _columnsGrid, _foreignKeysGrid, _indicesGrid);
        final TableInfo _existingGrid = TableInfo.read(_db, "grid");
        if (! _infoGrid.equals(_existingGrid)) {
          return new RoomOpenHelper.ValidationResult(false, "grid(com.amaze.filemanager.database.models.utilities.Grid).\n"
                  + " Expected:\n" + _infoGrid + "\n"
                  + " Found:\n" + _existingGrid);
        }
        final HashMap<String, TableInfo.Column> _columnsHidden = new HashMap<String, TableInfo.Column>(2);
        _columnsHidden.put("_id", new TableInfo.Column("_id", "INTEGER", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsHidden.put("path", new TableInfo.Column("path", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysHidden = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesHidden = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoHidden = new TableInfo("hidden", _columnsHidden, _foreignKeysHidden, _indicesHidden);
        final TableInfo _existingHidden = TableInfo.read(_db, "hidden");
        if (! _infoHidden.equals(_existingHidden)) {
          return new RoomOpenHelper.ValidationResult(false, "hidden(com.amaze.filemanager.database.models.utilities.Hidden).\n"
                  + " Expected:\n" + _infoHidden + "\n"
                  + " Found:\n" + _existingHidden);
        }
        final HashMap<String, TableInfo.Column> _columnsHistory = new HashMap<String, TableInfo.Column>(2);
        _columnsHistory.put("_id", new TableInfo.Column("_id", "INTEGER", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsHistory.put("path", new TableInfo.Column("path", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysHistory = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesHistory = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoHistory = new TableInfo("history", _columnsHistory, _foreignKeysHistory, _indicesHistory);
        final TableInfo _existingHistory = TableInfo.read(_db, "history");
        if (! _infoHistory.equals(_existingHistory)) {
          return new RoomOpenHelper.ValidationResult(false, "history(com.amaze.filemanager.database.models.utilities.History).\n"
                  + " Expected:\n" + _infoHistory + "\n"
                  + " Found:\n" + _existingHistory);
        }
        final HashMap<String, TableInfo.Column> _columnsList = new HashMap<String, TableInfo.Column>(2);
        _columnsList.put("_id", new TableInfo.Column("_id", "INTEGER", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsList.put("path", new TableInfo.Column("path", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysList = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesList = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoList = new TableInfo("list", _columnsList, _foreignKeysList, _indicesList);
        final TableInfo _existingList = TableInfo.read(_db, "list");
        if (! _infoList.equals(_existingList)) {
          return new RoomOpenHelper.ValidationResult(false, "list(com.amaze.filemanager.database.models.utilities.List).\n"
                  + " Expected:\n" + _infoList + "\n"
                  + " Found:\n" + _existingList);
        }
        final HashMap<String, TableInfo.Column> _columnsSmb = new HashMap<String, TableInfo.Column>(3);
        _columnsSmb.put("_id", new TableInfo.Column("_id", "INTEGER", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsSmb.put("path", new TableInfo.Column("path", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsSmb.put("name", new TableInfo.Column("name", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysSmb = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesSmb = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoSmb = new TableInfo("smb", _columnsSmb, _foreignKeysSmb, _indicesSmb);
        final TableInfo _existingSmb = TableInfo.read(_db, "smb");
        if (! _infoSmb.equals(_existingSmb)) {
          return new RoomOpenHelper.ValidationResult(false, "smb(com.amaze.filemanager.database.models.utilities.SmbEntry).\n"
                  + " Expected:\n" + _infoSmb + "\n"
                  + " Found:\n" + _existingSmb);
        }
        final HashMap<String, TableInfo.Column> _columnsSftp = new HashMap<String, TableInfo.Column>(6);
        _columnsSftp.put("_id", new TableInfo.Column("_id", "INTEGER", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsSftp.put("path", new TableInfo.Column("path", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsSftp.put("name", new TableInfo.Column("name", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsSftp.put("pub_key", new TableInfo.Column("pub_key", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsSftp.put("ssh_key_name", new TableInfo.Column("ssh_key_name", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsSftp.put("ssh_key", new TableInfo.Column("ssh_key", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysSftp = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesSftp = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoSftp = new TableInfo("sftp", _columnsSftp, _foreignKeysSftp, _indicesSftp);
        final TableInfo _existingSftp = TableInfo.read(_db, "sftp");
        if (! _infoSftp.equals(_existingSftp)) {
          return new RoomOpenHelper.ValidationResult(false, "sftp(com.amaze.filemanager.database.models.utilities.SftpEntry).\n"
                  + " Expected:\n" + _infoSftp + "\n"
                  + " Found:\n" + _existingSftp);
        }
        return new RoomOpenHelper.ValidationResult(true, null);
      }
    }, "fd9be1eb18f13625e763342c783122da", "4bda0b9b57eb8b7cee624850dd237be7");
    final SupportSQLiteOpenHelper.Configuration _sqliteConfig = SupportSQLiteOpenHelper.Configuration.builder(configuration.context)
        .name(configuration.name)
        .callback(_openCallback)
        .build();
    final SupportSQLiteOpenHelper _helper = configuration.sqliteOpenHelperFactory.create(_sqliteConfig);
    return _helper;
  }

  @Override
  protected InvalidationTracker createInvalidationTracker() {
    final HashMap<String, String> _shadowTablesMap = new HashMap<String, String>(0);
    HashMap<String, Set<String>> _viewTables = new HashMap<String, Set<String>>(0);
    return new InvalidationTracker(this, _shadowTablesMap, _viewTables, "bookmarks","grid","hidden","history","list","smb","sftp");
  }

  @Override
  public void clearAllTables() {
    super.assertNotMainThread();
    final SupportSQLiteDatabase _db = super.getOpenHelper().getWritableDatabase();
    try {
      super.beginTransaction();
      _db.execSQL("DELETE FROM `bookmarks`");
      _db.execSQL("DELETE FROM `grid`");
      _db.execSQL("DELETE FROM `hidden`");
      _db.execSQL("DELETE FROM `history`");
      _db.execSQL("DELETE FROM `list`");
      _db.execSQL("DELETE FROM `smb`");
      _db.execSQL("DELETE FROM `sftp`");
      super.setTransactionSuccessful();
    } finally {
      super.endTransaction();
      _db.query("PRAGMA wal_checkpoint(FULL)").close();
      if (!_db.inTransaction()) {
        _db.execSQL("VACUUM");
      }
    }
  }

  @Override
  protected HiddenEntryDao hiddenEntryDao() {
    if (_hiddenEntryDao != null) {
      return _hiddenEntryDao;
    } else {
      synchronized(this) {
        if(_hiddenEntryDao == null) {
          _hiddenEntryDao = new HiddenEntryDao_Impl(this);
        }
        return _hiddenEntryDao;
      }
    }
  }

  @Override
  protected GridEntryDao gridEntryDao() {
    if (_gridEntryDao != null) {
      return _gridEntryDao;
    } else {
      synchronized(this) {
        if(_gridEntryDao == null) {
          _gridEntryDao = new GridEntryDao_Impl(this);
        }
        return _gridEntryDao;
      }
    }
  }

  @Override
  protected ListEntryDao listEntryDao() {
    if (_listEntryDao != null) {
      return _listEntryDao;
    } else {
      synchronized(this) {
        if(_listEntryDao == null) {
          _listEntryDao = new ListEntryDao_Impl(this);
        }
        return _listEntryDao;
      }
    }
  }

  @Override
  protected HistoryEntryDao historyEntryDao() {
    if (_historyEntryDao != null) {
      return _historyEntryDao;
    } else {
      synchronized(this) {
        if(_historyEntryDao == null) {
          _historyEntryDao = new HistoryEntryDao_Impl(this);
        }
        return _historyEntryDao;
      }
    }
  }

  @Override
  protected BookmarkEntryDao bookmarkEntryDao() {
    if (_bookmarkEntryDao != null) {
      return _bookmarkEntryDao;
    } else {
      synchronized(this) {
        if(_bookmarkEntryDao == null) {
          _bookmarkEntryDao = new BookmarkEntryDao_Impl(this);
        }
        return _bookmarkEntryDao;
      }
    }
  }

  @Override
  protected SmbEntryDao smbEntryDao() {
    if (_smbEntryDao != null) {
      return _smbEntryDao;
    } else {
      synchronized(this) {
        if(_smbEntryDao == null) {
          _smbEntryDao = new SmbEntryDao_Impl(this);
        }
        return _smbEntryDao;
      }
    }
  }

  @Override
  protected SftpEntryDao sftpEntryDao() {
    if (_sftpEntryDao != null) {
      return _sftpEntryDao;
    } else {
      synchronized(this) {
        if(_sftpEntryDao == null) {
          _sftpEntryDao = new SftpEntryDao_Impl(this);
        }
        return _sftpEntryDao;
      }
    }
  }
}
