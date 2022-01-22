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
import com.amaze.filemanager.database.daos.CloudEntryDao;
import com.amaze.filemanager.database.daos.CloudEntryDao_Impl;
import com.amaze.filemanager.database.daos.EncryptedEntryDao;
import com.amaze.filemanager.database.daos.EncryptedEntryDao_Impl;
import com.amaze.filemanager.database.daos.SortDao;
import com.amaze.filemanager.database.daos.SortDao_Impl;
import com.amaze.filemanager.database.daos.TabDao;
import com.amaze.filemanager.database.daos.TabDao_Impl;
import java.lang.Override;
import java.lang.String;
import java.lang.SuppressWarnings;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

@SuppressWarnings({"unchecked", "deprecation"})
public final class ExplorerDatabase_Impl extends ExplorerDatabase {
  private volatile TabDao _tabDao;

  private volatile SortDao _sortDao;

  private volatile EncryptedEntryDao _encryptedEntryDao;

  private volatile CloudEntryDao _cloudEntryDao;

  @Override
  protected SupportSQLiteOpenHelper createOpenHelper(DatabaseConfiguration configuration) {
    final SupportSQLiteOpenHelper.Callback _openCallback = new RoomOpenHelper(configuration, new RoomOpenHelper.Delegate(8) {
      @Override
      public void createAllTables(SupportSQLiteDatabase _db) {
        _db.execSQL("CREATE TABLE IF NOT EXISTS `tab` (`tab_no` INTEGER NOT NULL, `path` TEXT, `home` TEXT, PRIMARY KEY(`tab_no`))");
        _db.execSQL("CREATE TABLE IF NOT EXISTS `sort` (`path` TEXT NOT NULL, `type` INTEGER NOT NULL, PRIMARY KEY(`path`))");
        _db.execSQL("CREATE TABLE IF NOT EXISTS `encrypted` (`_id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, `path` TEXT, `password` TEXT)");
        _db.execSQL("CREATE TABLE IF NOT EXISTS `cloud` (`_id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, `service` INTEGER, `persist` TEXT)");
        _db.execSQL("CREATE TABLE IF NOT EXISTS room_master_table (id INTEGER PRIMARY KEY,identity_hash TEXT)");
        _db.execSQL("INSERT OR REPLACE INTO room_master_table (id,identity_hash) VALUES(42, '06766b689063c1bcaa4d0df3fd06f5e6')");
      }

      @Override
      public void dropAllTables(SupportSQLiteDatabase _db) {
        _db.execSQL("DROP TABLE IF EXISTS `tab`");
        _db.execSQL("DROP TABLE IF EXISTS `sort`");
        _db.execSQL("DROP TABLE IF EXISTS `encrypted`");
        _db.execSQL("DROP TABLE IF EXISTS `cloud`");
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
        final HashMap<String, TableInfo.Column> _columnsTab = new HashMap<String, TableInfo.Column>(3);
        _columnsTab.put("tab_no", new TableInfo.Column("tab_no", "INTEGER", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsTab.put("path", new TableInfo.Column("path", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsTab.put("home", new TableInfo.Column("home", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysTab = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesTab = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoTab = new TableInfo("tab", _columnsTab, _foreignKeysTab, _indicesTab);
        final TableInfo _existingTab = TableInfo.read(_db, "tab");
        if (! _infoTab.equals(_existingTab)) {
          return new RoomOpenHelper.ValidationResult(false, "tab(com.amaze.filemanager.database.models.explorer.Tab).\n"
                  + " Expected:\n" + _infoTab + "\n"
                  + " Found:\n" + _existingTab);
        }
        final HashMap<String, TableInfo.Column> _columnsSort = new HashMap<String, TableInfo.Column>(2);
        _columnsSort.put("path", new TableInfo.Column("path", "TEXT", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsSort.put("type", new TableInfo.Column("type", "INTEGER", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysSort = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesSort = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoSort = new TableInfo("sort", _columnsSort, _foreignKeysSort, _indicesSort);
        final TableInfo _existingSort = TableInfo.read(_db, "sort");
        if (! _infoSort.equals(_existingSort)) {
          return new RoomOpenHelper.ValidationResult(false, "sort(com.amaze.filemanager.database.models.explorer.Sort).\n"
                  + " Expected:\n" + _infoSort + "\n"
                  + " Found:\n" + _existingSort);
        }
        final HashMap<String, TableInfo.Column> _columnsEncrypted = new HashMap<String, TableInfo.Column>(3);
        _columnsEncrypted.put("_id", new TableInfo.Column("_id", "INTEGER", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsEncrypted.put("path", new TableInfo.Column("path", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsEncrypted.put("password", new TableInfo.Column("password", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysEncrypted = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesEncrypted = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoEncrypted = new TableInfo("encrypted", _columnsEncrypted, _foreignKeysEncrypted, _indicesEncrypted);
        final TableInfo _existingEncrypted = TableInfo.read(_db, "encrypted");
        if (! _infoEncrypted.equals(_existingEncrypted)) {
          return new RoomOpenHelper.ValidationResult(false, "encrypted(com.amaze.filemanager.database.models.explorer.EncryptedEntry).\n"
                  + " Expected:\n" + _infoEncrypted + "\n"
                  + " Found:\n" + _existingEncrypted);
        }
        final HashMap<String, TableInfo.Column> _columnsCloud = new HashMap<String, TableInfo.Column>(3);
        _columnsCloud.put("_id", new TableInfo.Column("_id", "INTEGER", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsCloud.put("service", new TableInfo.Column("service", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsCloud.put("persist", new TableInfo.Column("persist", "TEXT", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysCloud = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesCloud = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoCloud = new TableInfo("cloud", _columnsCloud, _foreignKeysCloud, _indicesCloud);
        final TableInfo _existingCloud = TableInfo.read(_db, "cloud");
        if (! _infoCloud.equals(_existingCloud)) {
          return new RoomOpenHelper.ValidationResult(false, "cloud(com.amaze.filemanager.database.models.explorer.CloudEntry).\n"
                  + " Expected:\n" + _infoCloud + "\n"
                  + " Found:\n" + _existingCloud);
        }
        return new RoomOpenHelper.ValidationResult(true, null);
      }
    }, "06766b689063c1bcaa4d0df3fd06f5e6", "3fb2e703009c5d86d6585d856f21ebbc");
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
    return new InvalidationTracker(this, _shadowTablesMap, _viewTables, "tab","sort","encrypted","cloud");
  }

  @Override
  public void clearAllTables() {
    super.assertNotMainThread();
    final SupportSQLiteDatabase _db = super.getOpenHelper().getWritableDatabase();
    try {
      super.beginTransaction();
      _db.execSQL("DELETE FROM `tab`");
      _db.execSQL("DELETE FROM `sort`");
      _db.execSQL("DELETE FROM `encrypted`");
      _db.execSQL("DELETE FROM `cloud`");
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
  protected TabDao tabDao() {
    if (_tabDao != null) {
      return _tabDao;
    } else {
      synchronized(this) {
        if(_tabDao == null) {
          _tabDao = new TabDao_Impl(this);
        }
        return _tabDao;
      }
    }
  }

  @Override
  protected SortDao sortDao() {
    if (_sortDao != null) {
      return _sortDao;
    } else {
      synchronized(this) {
        if(_sortDao == null) {
          _sortDao = new SortDao_Impl(this);
        }
        return _sortDao;
      }
    }
  }

  @Override
  protected EncryptedEntryDao encryptedEntryDao() {
    if (_encryptedEntryDao != null) {
      return _encryptedEntryDao;
    } else {
      synchronized(this) {
        if(_encryptedEntryDao == null) {
          _encryptedEntryDao = new EncryptedEntryDao_Impl(this);
        }
        return _encryptedEntryDao;
      }
    }
  }

  @Override
  protected CloudEntryDao cloudEntryDao() {
    if (_cloudEntryDao != null) {
      return _cloudEntryDao;
    } else {
      synchronized(this) {
        if(_cloudEntryDao == null) {
          _cloudEntryDao = new CloudEntryDao_Impl(this);
        }
        return _cloudEntryDao;
      }
    }
  }
}
