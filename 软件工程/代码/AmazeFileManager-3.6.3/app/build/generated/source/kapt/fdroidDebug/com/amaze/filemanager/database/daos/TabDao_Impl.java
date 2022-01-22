package com.amaze.filemanager.database.daos;

import android.database.Cursor;
import androidx.room.EmptyResultSetException;
import androidx.room.EntityDeletionOrUpdateAdapter;
import androidx.room.EntityInsertionAdapter;
import androidx.room.RoomDatabase;
import androidx.room.RoomSQLiteQuery;
import androidx.room.RxRoom;
import androidx.room.SharedSQLiteStatement;
import androidx.room.util.CursorUtil;
import androidx.room.util.DBUtil;
import androidx.sqlite.db.SupportSQLiteStatement;
import com.amaze.filemanager.database.models.explorer.Tab;
import io.reactivex.Completable;
import io.reactivex.Single;
import java.lang.Exception;
import java.lang.Override;
import java.lang.String;
import java.lang.SuppressWarnings;
import java.lang.Void;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;

@SuppressWarnings({"unchecked", "deprecation"})
public final class TabDao_Impl implements TabDao {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<Tab> __insertionAdapterOfTab;

  private final EntityDeletionOrUpdateAdapter<Tab> __updateAdapterOfTab;

  private final SharedSQLiteStatement __preparedStmtOfClear;

  public TabDao_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfTab = new EntityInsertionAdapter<Tab>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR REPLACE INTO `tab` (`tab_no`,`path`,`home`) VALUES (?,?,?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, Tab value) {
        stmt.bindLong(1, value.tabNumber);
        if (value.path == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.path);
        }
        if (value.home == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindString(3, value.home);
        }
      }
    };
    this.__updateAdapterOfTab = new EntityDeletionOrUpdateAdapter<Tab>(__db) {
      @Override
      public String createQuery() {
        return "UPDATE OR REPLACE `tab` SET `tab_no` = ?,`path` = ?,`home` = ? WHERE `tab_no` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, Tab value) {
        stmt.bindLong(1, value.tabNumber);
        if (value.path == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.path);
        }
        if (value.home == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindString(3, value.home);
        }
        stmt.bindLong(4, value.tabNumber);
      }
    };
    this.__preparedStmtOfClear = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM tab";
        return _query;
      }
    };
  }

  @Override
  public Completable insertTab(final Tab tab) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __insertionAdapterOfTab.insert(tab);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public void update(final Tab tab) {
    __db.assertNotSuspendingTransaction();
    __db.beginTransaction();
    try {
      __updateAdapterOfTab.handle(tab);
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
    }
  }

  @Override
  public Completable clear() {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        final SupportSQLiteStatement _stmt = __preparedStmtOfClear.acquire();
        __db.beginTransaction();
        try {
          _stmt.executeUpdateDelete();
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
          __preparedStmtOfClear.release(_stmt);
        }
      }
    });
  }

  @Override
  public Single<Tab> find(final int tabNo) {
    final String _sql = "SELECT `tab`.`tab_no` AS `tab_no`, `tab`.`path` AS `path`, `tab`.`home` AS `home` FROM tab WHERE tab_no = ?";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 1);
    int _argIndex = 1;
    _statement.bindLong(_argIndex, tabNo);
    return RxRoom.createSingle(new Callable<Tab>() {
      @Override
      public Tab call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfTabNumber = CursorUtil.getColumnIndexOrThrow(_cursor, "tab_no");
          final int _cursorIndexOfPath = CursorUtil.getColumnIndexOrThrow(_cursor, "path");
          final int _cursorIndexOfHome = CursorUtil.getColumnIndexOrThrow(_cursor, "home");
          final Tab _result;
          if(_cursor.moveToFirst()) {
            final int _tmpTabNumber;
            _tmpTabNumber = _cursor.getInt(_cursorIndexOfTabNumber);
            final String _tmpPath;
            _tmpPath = _cursor.getString(_cursorIndexOfPath);
            final String _tmpHome;
            _tmpHome = _cursor.getString(_cursorIndexOfHome);
            _result = new Tab(_tmpTabNumber,_tmpPath,_tmpHome);
          } else {
            _result = null;
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }

  @Override
  public Single<List<Tab>> list() {
    final String _sql = "SELECT `tab`.`tab_no` AS `tab_no`, `tab`.`path` AS `path`, `tab`.`home` AS `home` FROM tab";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 0);
    return RxRoom.createSingle(new Callable<List<Tab>>() {
      @Override
      public List<Tab> call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfTabNumber = CursorUtil.getColumnIndexOrThrow(_cursor, "tab_no");
          final int _cursorIndexOfPath = CursorUtil.getColumnIndexOrThrow(_cursor, "path");
          final int _cursorIndexOfHome = CursorUtil.getColumnIndexOrThrow(_cursor, "home");
          final List<Tab> _result = new ArrayList<Tab>(_cursor.getCount());
          while(_cursor.moveToNext()) {
            final Tab _item;
            final int _tmpTabNumber;
            _tmpTabNumber = _cursor.getInt(_cursorIndexOfTabNumber);
            final String _tmpPath;
            _tmpPath = _cursor.getString(_cursorIndexOfPath);
            final String _tmpHome;
            _tmpHome = _cursor.getString(_cursorIndexOfHome);
            _item = new Tab(_tmpTabNumber,_tmpPath,_tmpHome);
            _result.add(_item);
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }
}
